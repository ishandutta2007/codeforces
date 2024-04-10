// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>cx(51),cy(51),x(n*4+1),y(n*4+1);
    for(int i=0;i<=n*4;++i){
        cin>>x[i]>>y[i];
        ++cx[x[i]];
        ++cy[y[i]];
    }
    int x1,y1,x2,y2;
    for(int i=50;i>=0;--i){
        if(cx[i]>1){
            x1=i;
        }
    }
    for(int i=0;i<=50;++i){
        if(cx[i]>1){
            x2=i;
        }
    }
    for(int i=50;i>=0;--i){
        if(cy[i]>1){
            y1=i;
        }
    }
    for(int i=0;i<=50;++i){
        if(cy[i]>1){
            y2=i;
        }
    }
    for(int i=0;i<=n*4;++i){
        if(!(x[i]>=x1&&x[i]<=x2&&y[i]>=y1&&y[i]<=y2&&(x[i]==x1||x[i]==x2||y[i]==y1||y[i]==y2))){
            cout<<x[i]<<' '<<y[i]<<endl;
            return 0;
        }
    }
    return 0;
}