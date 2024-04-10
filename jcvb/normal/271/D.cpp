#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<deque>
#define P 17
#define Q 9985601
using namespace std;
char str[1505];
char str2[30];
int ok[150];
int k;
int l;
int bad[1505]={0};
set<string>st;
long long hash[1505];
vector<pair<int,int> > vis[10000000];
long bigpow[1505]={0};
long ans=0;
int equal(int l1,int r1,int l2,int r2){
    if(l2-l1!=r2-r1)return 0;
    for (int i=0;i<r1-l1+1;i++)
        if(str[l1+i]!=str[l2+i])return 0;
    return 1;
}
void insert(int L,int R){
     long long h;
     if(L==0)h=hash[R];
     else h=((hash[R]-hash[L-1]*bigpow[R-L+1]%Q)%Q+Q)%Q;
     
     if(vis[h].size()==0){
                  vis[h].push_back(make_pair(L,R));
                  ans++;
     }else{
           for (int i=0;i<vis[h].size();i++)
               if(equal(L,R,vis[h][i].first,vis[h][i].second))goto lbl;
           vis[h].push_back(make_pair(L,R));
           ans++;
           lbl:;
     }
}
                 
int main()
{
    gets(str);
    gets(str2);
    for (int i=0;i<26;i++)ok[i+'a']=str2[i]=='1';
    scanf("%d",&k);
    l=strlen(str);
    for (int i=0;i<l;i++)bad[i]=!ok[str[i]];
    for (int i=1;i<l;i++)bad[i]+=bad[i-1];
    
    hash[0]=str[0];
    for (int i=1;i<l;i++)hash[i]=(hash[i-1]*P+str[i])%Q;
    bigpow[0]=1;
    for (int i=1;i<=l;i++)bigpow[i]=bigpow[i-1]*P%Q;
    for (int rig=0;rig<l;rig++)
        if(bad[rig]<=k)insert(0,rig);//st.insert(string(str,0,rig+1));
        else break;
    for (int lef=1;lef<l;lef++)
        for (int rig=lef;rig<l;rig++)
            if(bad[rig]-bad[lef-1]<=k)insert(lef,rig);//st.insert(string(str+lef,str+rig+1));
            else break;
    printf("%ld\n",ans);
  //  for (set<string>::iterator it=st.begin();it!=st.end();it++)cout<<*it<<endl;
    return 0;
}