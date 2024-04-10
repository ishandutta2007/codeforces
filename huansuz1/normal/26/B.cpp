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
#define mp make_pair
#define f first
#define s second

using namespace std;

string s;
int ans,x,y;

int main(){   
    cin>>s;

    for (int i=0; i<s.length(); i++){
        if (s[i]=='(') x++; else
            if (x>0) {x--; ans+=2; }    
    }
    cout<<ans;


return 0;
}