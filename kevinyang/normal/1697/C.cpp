#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        bool f = true;
        if(count(s.begin(),s.end(),'a')!=count(t.begin(),t.end(),'a'))f = false;
        if(count(s.begin(),s.end(),'b')!=count(t.begin(),t.end(),'b'))f = false;
        if(count(s.begin(),s.end(),'c')!=count(t.begin(),t.end(),'c'))f = false;
        vector<char>a;
        vector<char>b;
        vector<int>c;
        vector<int>d;
        for(int i = 0; i<n; i++){
            if(s[i]!='b'){
                a.push_back(s[i]);
                c.push_back(i);
            }
            if(t[i]!='b'){
                b.push_back(t[i]);
                d.push_back(i);
            }
        }
        if(a.size()!=b.size())f = false;
        for(int i = 0; i<min(a.size(),b.size()); i++){
            if(a[i]!=b[i])f = false;
            if(c[i]>d[i]&&a[i]=='a')f = false;
            if(c[i]<d[i]&&a[i]=='c')f = false;
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}