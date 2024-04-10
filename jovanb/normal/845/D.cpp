#include <bits/stdc++.h>
using namespace std;
stack <long> q;
int main()
{
    long n,i,bro=0,br=0;
    cin>>n;
    short x,s,cs=0;
    for(i=0;i<n;i++){
        cin>>x;
        if(x==6)bro++;
        if(x==4)bro=0;
        if(x==2){br+=bro;bro=0;}
        if(x==3){
            cin>>s;
            q.push(s);
            while(!q.empty()){
             if(cs>q.top()){
                br++;
                q.pop();
            }
            else break;}}
        if(x==5){
            while(q.empty()==false){
                q.pop();
            }
        }
        if(x==1){
            cin>>cs;
            while(!q.empty()){
             if(cs>q.top()){
                br++;
                q.pop();
            }
            else break;}
        }

    }
    cout<<br;
    return 0;
}