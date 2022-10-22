#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e4+10;
const ll mod=998244353;
string s,ss;
void hail(char tar){
    vector<string>v,vv;
    string cur;
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]==tar)v.push_back(cur),cur.clear();
        else cur.push_back(s[i]);
    }
    v.push_back(cur),cur.clear();
    for(i=0;i<ss.size();i++){
        if(ss[i]==tar)vv.push_back(cur),cur.clear();
        else cur.push_back(ss[i]);
    }
    vv.push_back(cur),cur.clear();
    if(v.size()==1){
        return;
    }
    string ans;
    for(i=0;i<v.size()/2;i++){
        if(v[i].size()&&vv[i].size()){
            if(v[i].size()==vv[i].size()&&v[i]!=vv[i]){
                v[i].pop_back();
            }
            if(v[i].size()<vv[i].size())for(char c:v[i])ans.push_back(c);
            else for(char c:vv[i])ans.push_back(c);
        }
        if(i!=v.size()/2-1)ans.push_back(tar);
    }
    string o;
    o=ans;
    if(v.size()&1){
        o.push_back(tar);
        if(v[v.size()/2].size()%2==0)v[v.size()/2].pop_back();
        for(char c:v[v.size()/2])o.push_back(c);
        o.push_back(tar);
    }
    else o.push_back(tar);
    reverse(ans.begin(),ans.end());
    for(char c:ans)o.push_back(c);
    if(o.size()>=s.size()/2){
        printf("%s",o.c_str());
        exit(0);
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>s;
    ss=s;
    reverse(ss.begin(),ss.end());
    hail('a');
    hail('b');
    hail('c');
    assert(0);
}