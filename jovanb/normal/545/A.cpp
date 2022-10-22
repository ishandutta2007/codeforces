#include <bits/stdc++.h>
using namespace std;

queue <int> q;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,dobar,br=0,i,j,x;
    cin>>n;
    for(i=1;i<=n;i++){
        dobar=1;
        for(j=1;j<=n;j++){
            cin>>x;
            if(x==1 || x==3)dobar=0;
        }
        if(dobar==1){
            br++;
            q.push(i);
        }
    }
    cout<<br<<"\n";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}