#include <bits/stdc++.h>
#define int unsigned long long
#define fi first
#define se second
using namespace std; 
const int MAX=pow(2,32)-1;
void gg(){
    cout<<"OVERFLOW!!!"<<endl;
    return;
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int l;
    cin>>l;
    int t;
    string s;
    stack<int>oof;
    int now=1,sum=0,toobig=0;
    bool explode=false;
    for(int i=0;i<l;i++){
        cin>>s;
        if(s=="add"){
            if(explode){
                gg();
                return 0;
            }
            if(MAX-sum<now){
                gg();
                return 0;
            }
            sum+=now;
        }
        else if(s=="end"){
            if(!explode){
                now/=oof.top();
                oof.pop();
            }
            else{
                toobig--;
                if(toobig==0)explode=0;
            }
        }
        else{
            cin>>t;
            if(explode){
                toobig++;
            }
            else if(t>(MAX/now)){
                explode=1;
                toobig++;
            }
            else{
                now*=t;
                oof.push(t);
            }
        }
    }
    cout<<sum<<endl;
	return 0;
}