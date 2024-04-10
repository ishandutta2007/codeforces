#include <bits/stdc++.h>
using namespace std;

bool brzi[100][100];
int post[100];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,i,fi=0,se=0,x,y,j;
    cin>>n;
    for(i=1;i<=(n*(n-1))/2-1;i++){
        cin>>x>>y;
        brzi[x][y]=1;
        post[x]++;
        post[y]++;
    }
    for(i=1;i<=n;i++){
        if(post[i]!=n-1){
            if(fi==0)fi=i;
            else{
                se=i;
                for(j=1;j<=n;j++){
                    if(j!=fi && j!=se){
                        if(brzi[fi][j] && brzi[j][se]){cout<<fi<<" "<<se;return 0;}
                        if(brzi[se][j] && brzi[j][fi]){cout<<se<<" "<<fi;return 0;}
                    }
                }
                cout<<fi<<" "<<se;
                return 0;
            }
        }
    }
    return 0;
}