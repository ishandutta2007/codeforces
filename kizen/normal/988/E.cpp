#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
string s;

int sol(char a, char b){
    string ss = s; int val = 0, ff = 0;
    for(int i=(int)ss.size()-1;i>=0;i--) if(ss[i]==b){
        for(int j=i;j<(int)ss.size()-1;j++) val++, swap(ss[j], ss[j+1]);
        ff++;
        break;
    }
    for(int i=(int)ss.size()-2;i>=0;i--) if(ss[i]==a){
        for(int j=i;j<(int)ss.size()-2;j++) val++, swap(ss[j], ss[j+1]);
        ff++;
        break;
    }
    int f = 0;
    if(ss[0]=='0'){
        for(int i=1;i<(int)ss.size()-2;i++) if(ss[i]!='0'){
            swap(ss[0], ss[i]);
            f = i; break;
        }
    }
    if(ss[0]!='0'&&ff==2){
        return f+val;
    }
    return INF;
}

int main(){
    int ans = INF;
    cin >> s;
    ans = min(ans, sol('0', '0'));
    ans = min(ans, sol('2', '5'));
    ans = min(ans, sol('5', '0'));
    ans = min(ans, sol('7', '5'));
    printf("%d", ans==INF? -1:ans);
    return 0;
}