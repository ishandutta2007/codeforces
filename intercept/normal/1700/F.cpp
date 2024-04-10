#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=2e5+9;
int n,ta,tb;
ll ans;
int a[2][M],b[2][M];
vector<int>A[2],B[2];
int main(){
    scanf("%d",&n);
    for(int o=0;o<2;++o){
        for(int i=1;i<=n;++i)scanf("%d",&a[o][i]),ta+=a[o][i];
    }
    for(int o=0;o<2;++o){
        for(int i=1;i<=n;++i)scanf("%d",&b[o][i]),tb+=b[o][i];
    }
    if(ta!=tb){
        puts("-1");
        return 0;
    }  
    for(int o=0;o<2;++o){
        for(int i=1;i<=n;++i)if(a[o][i]&&b[o][i])a[o][i]=b[o][i]=0;
    }
    for(int i=1;i<=n;++i){
        if(a[0][i]&&a[1][i]){
            if(B[0].size()){
                ans+=i-B[0].back(),B[0].pop_back();
                if(B[1].size())ans+=i-B[1].back(),B[1].pop_back();
                else if(B[0].size()){
                    ans+=i-B[0].back()+1,B[0].pop_back();
                }
                else A[1].eb(i);
            }
            else if(B[1].size()){
                ans+=i-B[1].back(),B[1].pop_back();
                if(B[1].size()){
                    ans+=i-B[1].back()+1,B[1].pop_back();
                }
                else A[0].eb(i);
            }
            else{
                A[1].eb(i);
                A[0].eb(i);
            }
        }
        else if(a[0][i]){
            if(B[0].size())ans+=i-B[0].back(),B[0].pop_back();
            else if(B[1].size())ans+=i-B[1].back()+1,B[1].pop_back();
            else A[0].eb(i);
        }
        else if(a[1][i]){
            if(B[1].size())ans+=i-B[1].back(),B[1].pop_back();
            else if(B[0].size())ans+=i-B[0].back()+1,B[0].pop_back();
            else A[1].eb(i);
        }

        if(b[0][i]&&b[1][i]){
            if(A[0].size()){
                ans+=i-A[0].back(),A[0].pop_back();
                if(A[1].size())ans+=i-A[1].back(),A[1].pop_back();
                else if(A[0].size()){
                    ans+=i-A[0].back()+1,A[0].pop_back();
                }
                else B[1].eb(i);
            }
            else if(A[1].size()){
                ans+=i-A[1].back(),A[1].pop_back();
                if(A[1].size()){
                    ans+=i-A[1].back()+1,A[1].pop_back();
                }
                else B[0].eb(i);
            }
            else{
                B[1].eb(i);
                B[0].eb(i);
            }
        }
        else if(b[0][i]){
            if(A[0].size())ans+=i-A[0].back(),A[0].pop_back();
            else if(A[1].size())ans+=i-A[1].back()+1,A[1].pop_back();
            else B[0].eb(i);
        }
        else if(b[1][i]){
            if(A[1].size())ans+=i-A[1].back(),A[1].pop_back();
            else if(A[0].size())ans+=i-A[0].back()+1,A[0].pop_back();
            else B[1].eb(i);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
3
0 1 0
1 1 0
1 0 1
0 0 1
*/