#include <bits/stdc++.h>

using namespace std;
struct trno {
struct trno *ch[3];
int is;
};
struct trno *gtno()
{
    struct trno *tmp=new trno;
    tmp->is=0;
    for(int i=0;i<2;i++)
        tmp->ch[i]= NULL;

    return tmp;

}
void ins (struct trno *root,int x)
{
    struct trno *tmp=root;
    tmp->is++;
    for(int i=30;i>=0;i--){

        int u=((x>>i)&(1));
        if(!tmp->ch[u])tmp->ch[u]=gtno();
    tmp=tmp->ch[u];
    tmp->is++;
    }

    }
    void del(trno *root,int x)
    {
        trno *tmp=root;

        tmp->is--;
        for(int i=30;i>=0;i--)
        {
            int u=((x>>i)&1);

          tmp->ch[u]->is--;
          if(tmp->ch[u]->is==0){tmp->ch[u]=NULL;break;}
          tmp=tmp->ch[u];
        }
    }
    int ser(trno *root,int x)
    {

        int ans=0;
        trno *tmp=root;
        for(int i=30;i>=0;i--)
        {

           int u=((x>>i)&(1));
            if(tmp->ch[1-u]!=NULL){ans|=(1<<i);tmp=tmp->ch[1-u];}
            else
            tmp=tmp->ch[u];

        }
        return ans;
    }
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;

    struct trno *root =gtno();
int x;
char c;
ins(root,0);
    for(int i=0;i<n;i++)
    {
       cin>>c>>x;
       if(c=='+')
    ins(root,x);
    if(c=='-')del(root,x);
    if(c=='?')cout<<ser(root,x)<<endl;
    }

    return 0;
}