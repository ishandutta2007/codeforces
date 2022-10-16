#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n-10;i++){
        if(s[i]=='8')cnt++;
    }
    if(cnt>(n-10)/2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}