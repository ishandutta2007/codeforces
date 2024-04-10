#include <bits/stdc++.h>

using namespace std;
int mat[106][106];
int zbir[106];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n,m,k,maxi,br1,br=0,brr=0,i,j;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>mat[i][j];
        }
    }
    for(j=1;j<=m;j++){
        zbir[0]=0;
        for(i=1;i<=n;i++){
            zbir[i]=zbir[i-1]+mat[i][j];
        }
        maxi=0;
        br1=0;
        for(i=1;i<=n;i++){
            maxi=max(maxi,zbir[min(i+k-1,n)]-zbir[i-1]);
        }
        for(i=1;i<=n;i++){
            if(mat[i][j]==1){
                if(zbir[min(i+k-1,n)]-zbir[i-1]==maxi){brr+=br1;break;}
                else br1++;
            }
        }
        br+=maxi;
    }
    cout<<br<<endl<<brr;
    return 0;
}