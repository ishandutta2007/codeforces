#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
//#define mp make_pair
#define f first
#define s second

using namespace std;

string s,l;
int n,m;
int main(){
    cin>>s;
    for (int i=0;i <s.length(); i++) {
        l="";
        string x=s;
        for (int j=i; j<s.length(); j++) {
            l+=s[j];
            s[i]=' ';
            for (int o=0; o<s.length(); o++)
                if (s[o]==l[0] ) {
                    int p=0;
                    for (int e=0; e<l.length(); e++)
                        if (l[e]!=s[o+e]) {p=1; break; }
                    if (p==0) m=max(j-i+1,m);
                }
        }
        s=x;
    }
    cout<<m;


return 0;
}