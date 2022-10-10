//Template for Dev-C++ 5.3.0.4 by unlimitedsky
//2013 March 4 20:58 (UTC +07.00)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FOR(i,a,b,c) for (int i = a; i <= b; i+=c)
#define FORR(i,a,b,c) for (int i = a; i >= b; i-=c)
#define INC(i,a,b) for (int i = a; i <= b; i++)
#define DEC(i,a,b) for (int i = a; i >= b; i--)
#define MP make_pair
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a)
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int n, ar[500005], ctr, awal;

bool fcomp(int a, int b){
    if (a < b) return true;
    else return false;
}

int main(){
    ctr = 0;
    reset(ar,0);
    
    scanf("%d", &n);
    INC(i,0,n-1){
        scanf("%d", &ar[i]);
    }
    
    sort(ar,ar+n,fcomp);
    
    awal = (n >> 1) - 1;
    DEC(i,n-1,(n>>1)){
        while(awal >= 0 && (ar[awal] > (ar[i]>>1)))
            awal--;
        
        if (awal >= 0){
            awal--;
            ctr++;
        }
        else break;
    }
    
    printf("%d\n", n-ctr);
    
    return 0;
}