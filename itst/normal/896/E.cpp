#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<immintrin.h>
#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
    int a = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)){a = a * 10 + c - 48; c = getchar();}
    return a;
}
typedef long long ll;
int arr[100003] , N , M;

void mdy(int L , int R , int val){
    __m256i now = _mm256_set1_epi32(val);
    int *lft = arr + L , *rht = arr + R;
    while((ll)lft % 32 && lft <= rht){
        if(*lft > val) *lft -= val;
        ++lft;
    }
    while(lft + 7 <= rht){
        __m256i cur = *(__m256i*)lft;
        *(__m256i*)lft = _mm256_add_epi32(cur , _mm256_mullo_epi32(now , _mm256_cmpgt_epi32(cur , now)));
        lft += 8;
    }
    while(lft <= rht){
        if(*lft > val) *lft -= val;
        ++lft;
    }
}

int qry(int L , int R , int val){
    __m256i ans = _mm256_setzero_si256() , now = _mm256_set1_epi32(val);
    int *lft = arr + L , sum = 0;
    while(L <= R && L % 8){
        if(*lft == val) ++sum;
        ++lft; ++L;
    }
    while(L + 7 <= R){
        __m256i cur = *(__m256i*)lft;
        ans = _mm256_sub_epi32(ans , _mm256_cmpeq_epi32(cur , now));
        lft += 8; L += 8;
    }
    while(L <= R){
        if(*lft == val) ++sum;
        ++lft; ++L;
    }
    for(int i = 0 ; i < 8 ; ++i) sum += *((int*)&ans + i);
    return sum;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
#endif
    N = read(); M = read();
    for(int i = 1 ; i <= N ; ++i) arr[i] = read();
    for(int i = 1 ; i <= M ; ++i){
        int tp = read() , L = read() , R = read() , val = read();
        if(tp == 1) mdy(L , R , val);
        else printf("%d\n" , qry(L , R , val));
    }
    return 0;
}