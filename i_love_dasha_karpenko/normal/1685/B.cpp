#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
bool Check(bool col,vector<int> *V,vector<int> cnt,int *Z){
    int l1 = Z[col],l2 = Z[col^1];
    for(int len:V[col]){
        int g = min(len/2,l1);
        l1 -= g;
        len -= g*2;
        len -= 1;
        g = min(len/2,l2);
        l2 -= g;
    }
    for(int len:cnt){
        int g = min(len/2,l1);
        l1 -= g;
        len -= g*2;
        len -= 1;
        g = min(len/2,l2);
        l2 -= g;
    }
    for(int len:V[col^1]){
        if (l1){
            len -= 1;
            int g = min(len/2,l1);
            l1 -= g;
            len -= g*2;
        }
        int g = min(len/2,l2);
        l2 -= g;
    }
    return l1==0 && l2==0;
}
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    string s;
    cin>>s;  // abaab  let take ba then ab ba abababa|ababa|abababa|ababab|
    int n = s.length();
    int C[] = {0,0};
    for(int i = 0;i<n;i+=1){
        C[s[i]-'A'] += 1;
    }
    if (C[0]!=a+c+d || C[1]!=b+c+d){
        cout<<"NO\n";
        return;
    }  // abababa
    int Z[] = {c,d};
    vector<int> cnt;
    vector<int> V[2];
    for(int i = 0;i<n;i+=1){
        int j = i;
        while(j+1<n && s[j+1]!=s[j]){
            j += 1;
        }
        int len = j-i+1;
        bool start = s[i]=='B';
        i = j;
        if (len==1){
            continue;
        }
        if (len%2==0){
           V[start].push_back(len);
        }
        else{
            cnt.push_back(len);
        }
    }
    for(int c = 0;c<2;c+=1){
        sort(V[c].begin(),V[c].end(),greater<int>());
    }
    if (Check(0,V,cnt,Z) || Check(1,V,cnt,Z)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}