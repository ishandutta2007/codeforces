#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
const int mn=1e5+10;
void die(){
    printf("NO");
    exit(0);
}
bool al[256];
int num[256];
int main() {
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n-1;i++)if(s[i]=='.'&&s[i+1]=='.')die();
    for(int i='a';i<='z';i++)al[i]=1;
    for(int i='0';i<='9';i++)al[i]=1;
    for(int i='A';i<='Z';i++)al[i]=1;
    al['_']=1;
    for(int i=0;i<n;i++){
        if(!al[s[i]]&&s[i]!='/'&&s[i]!='@'&&s[i]!='.')die();
        num[s[i]]++;
    }
    if(num['/']>1)die();
    if(num['@']!=1)die();
    int i;
    for(i=0;i<n;i++){
        if(s[i]=='@'){
            if(i>=1&&i<=16)break;
            die();
        }
        else if(!al[s[i]])die();
    }
    int ln=i;
    for(i++;i<n;i++){
        if(s[i]=='.'){
            if(i==ln+1)die();
            ln=i;
        }
        else if(s[i]=='/'){
            if(i==ln+1)die();
            break;
        }
        else if(!al[s[i]]||i-ln>16)die();
    }
    if(i!=n){
        int h=0;
        for(i++;i<n;i++){
            if(!al[s[i]])die();
            h++;
        }
        if(h<1||h>16)die();
    }
    if(!al[s[n-1]])die();
    printf("YES");
}