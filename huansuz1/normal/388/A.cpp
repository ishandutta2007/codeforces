#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
#define mp make_pair
#define f first
#define s second

using namespace std;

const int MOD = (int)(1e9) + 7;
map<int,int> M;
set<int> S;
int n,a[123],b[123][123],c[123],ans,ma;

int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        b[c[a[i]]][a[i]]=1;        
        c[a[i]]++;
    }
    for (int j=1; j<=100; j++)
        for (int i=0; i<=100; i++)
            if (b[i][j]) {
                int q=0;

                for (int ii=0; ii<i; ii++) {
                    for (int jj=j; jj>=0; jj--)
                        if (b[ii][jj]==0) {q=1; swap(b[i][j],b[ii][jj]); break;}
                    if (q) break;       
                }
            }
    for (int i=0; i<=101; i++){
        int z=0;
        for (int j=0; j<=101; j++)
            z+=b[j][i]; 
        ans=max(z,ans);
    }

    cout<<ans;

        

    



    return 0;
}