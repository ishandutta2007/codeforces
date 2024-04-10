#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main(){
    int n;
    string s1,s2;
    cin>>n>>s1>>s2;
    queue<int>a,b;
    for(int i=0;i<n;i++){
        if(s1[i]=='a'&&s2[i]=='b')a.push(i+1);
        if(s1[i]=='b'&&s2[i]=='a')b.push(i+1);
    }
    int t=a.size()-b.size();
    if(abs(t)%2!=0){cout<<"-1"<<endl;return 0;}
    int op=0;
    queue<pair<int,int>>ans;
    while(a.size()>1){
        t=a.front();
        a.pop();
        ans.push(mp(t,a.front()));
        a.pop();
        op++;
    }
    while(b.size()>1){
        t=b.front();
        b.pop();
        ans.push(mp(t,b.front()));
        b.pop();
        op++;
    }
    if(!a.empty()){
        op+=2;
        ans.push(mp(a.front(),a.front()));
        ans.push(mp(a.front(),b.front()));
    }
    cout<<op<<endl;
    while (!ans.empty()){
        cout<<ans.front().fi<<" "<<ans.front().se<<endl;
        ans.pop();
    }
    return 0;
}