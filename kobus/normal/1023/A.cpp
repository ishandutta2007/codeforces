#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000007
#define p 41

string w,s;
bool can(int i,int j){
    if(i<0||j<0||i>=w.size()||j>=s.size())return 0;
    return 1;
}
bool match(int i,int j,int tam){
    if(tam==0)return 1;
    //cout<<i<<" "<<j<<" "<<tam<<endl;
    if(!can(i,j))return 0;
    while(tam--){
        if(!can(i,j))return 0;
        if(w[i]!=s[j])return 0;
        i++;
        j++;
    }
    return 1;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);

    int a,b;
    cin>>a>>b;
    cin>>w>>s;
    int posw=-1;
    for(int i=0;i<w.size();i++){
        if(w[i]=='*')posw=i;
    }
    if(posw==-1){
        if(w==s)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    int tam=w.size()-posw-1;
    if(w.size()-1<=s.size() && match(0,0,posw)
     && match(w.size()-tam,s.size()-tam,tam)){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}