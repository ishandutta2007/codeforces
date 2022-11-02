#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int maxn=1e5+5,maxm=1e6+5;
char s1[maxm],s2[maxm];
bool exi[maxn];
string ts;
vector<int> vt;
map<string,vector<int> > mp;
int main(){
    int i,j,n;
    int len;
    map<string,vector<int> >::iterator it;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%s%s",&s1,&s2);
        memset(exi,false,sizeof(exi));
        for (j=0;s2[j]!='\0';j++)
            exi[s2[j]-'a']=true;
        len=strlen(s1);
        while (len>0&&exi[s1[len-1]-'a'])
            len--;
        s1[len]='\0';
        ts=s1;
        ts+=' ';
        for (j=0;j<26;j++) if (exi[j])
            ts+='a'+j;
        if (mp.count(ts)) mp[ts].push_back(i+1);
        else{
            mp[ts]=vt; mp[ts].push_back(i+1);
        }
    }
    printf("%d\n",mp.size());
    for (it=mp.begin();it!=mp.end();it++){
        printf("%d",it->second.size());
        for (i=0;i<it->second.size();i++)
            printf(" %d",it->second[i]);
        puts("");
    }
    return 0;
}