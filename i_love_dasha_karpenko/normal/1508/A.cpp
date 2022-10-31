#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
ll gi(char ch){
    return ch-'0';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        ll cnta = 0,cntb = 0,cntc = 0;
        for(char to:a){
            if (to=='1')++cnta;
        }
        for(char to:b){
            if (to=='1')++cntb;
        }
        for(char to:c){
            if (to=='1')++cntc;
        }
        cnta = cnta>n;
        cntb = cntb>n;
        cntc = cntc>n;
        string s1,s2;
        ll symb = 0;
        if (cnta==cntb){
            symb = cnta;
            s1 = a;
            s2 = b;
        }
        else if (cnta==cntc){
            symb = cnta;
            s1 = a;
            s2 = c;
        }
        else{
            symb = cntb;
            s1 = b;
            s2 = c;
        }
        ll ptr1 = 0,ptr2 = 0;

        while(1){
            ll ct1 = 0,ct2 = 0;
            while(ptr1<s1.length() && gi(s1[ptr1])!=symb){
                ++ptr1;
                ++ct1;
            }
            while(ptr2<s2.length() && gi(s2[ptr2])!=symb){
                ++ptr2;
                ++ct2;
            }
            ll ct = max(ct1,ct2);
            for(ll i = 0;i<ct;++i){
                cout<<(symb^1);
            }
            if (ptr1<s1.length() || ptr2<s2.length())
                cout<<symb;
            else break;
            ++ptr1;
            ++ptr2;
        }
        cout<<endl;
    }
    return 0;
}