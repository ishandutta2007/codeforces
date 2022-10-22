#include <bits/stdc++.h>
using namespace std;
char toc(int x){
    if(x<10)return '0'+x;
    else if(x<36)return 'A'+x-10;
    else return 'a'+x-36;
}
int toi(char c){
    if(c<='9')return c-'0';
    else if(c<='Z')return c-'A'+10;
    else return c-'a'+36;
}
const int mn=2e5+10;
vector<int> g[mn],r[mn];
int in[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        string s;
        cin>>s;
        int a=toi(s[0]),b=toi(s[1]),c=toi(s[2]);
        g[a*62+b].push_back(b*62+c);
        r[b*62+c].push_back(a*62+b);
    }
    int b=-1,ea=0,eb=0;
    for(i=0;i<62*62;i++){
        if(b==-1&&g[i].size())b=i;
        if(g[i].size()>r[i].size())b=i,ea+=g[i].size()-r[i].size();
    }
    if(ea>1){printf("NO\n");return 0;}
    stack<int>s;
    vector<int>p;
    while(1){
        if(in[b]<g[b].size()){
            s.push(b);
            b=g[b][in[b]++];
        }
        else{
            p.push_back(b);
            if(!s.size())break;
            b=s.top();
            s.pop();
        }
    }
    reverse(p.begin(),p.end());
    if(p.size()!=n+1)printf("NO");
    else{
        printf("YES\n");
        printf("%c%c",toc(p[0]/62),toc(p[0]%62));
        for(i=1;i<p.size();i++)printf("%c",toc(p[i]%62));
    }
}