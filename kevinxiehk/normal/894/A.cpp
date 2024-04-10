 #include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            for(int k=j+1;k<s.length();k++){
                if(s[i]=='Q'&&s[j]=='A'&&s[k]=='Q')ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
//dllmcf