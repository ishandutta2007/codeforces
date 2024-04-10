#include <bits/stdc++.h>

using namespace std;
struct nod{
nod* ch[26];
};
nod *gt(){
nod *tmp=new nod;
for(int i=0;i<26;i++)tmp->ch[i]=NULL;
return tmp;

}
void ins(string s,nod* root)
{
    nod* tmp=root;

    for(int i=0;i<s.size();i++)
    {
        int u=s[i]-'a';
        if(tmp->ch[u]==NULL)tmp->ch[u]=gt();
        tmp=tmp->ch[u];

    }
}
bool win(nod* x)
{

    for(int i=0;i<26;i++)if((x->ch[i])!=NULL&&(win(x->ch[i])==false))
        return true;
    return false;
}
bool lose(nod* x)
{

bool res=true;
    for(int i=0;i<26;i++)if((x->ch[i])!=NULL)
    {
        res=false;
        if(lose(x->ch[i])==false)return true;
    }
    return res;
}

int n,k;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>k;
 struct nod *root= gt();
    for(int i=0;i<n;i++)
    {
        cin>>s;
        ins(s,root);
    }
    bool wn=win(root),ls=lose(root);
    if(wn&&ls){cout<<"First";return 0;}
    if(!wn){cout<<"Second";return 0;}
    if(k%2)cout<<"First";
    else cout<<"Second";
    return 0;
}