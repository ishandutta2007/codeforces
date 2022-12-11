#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct tree{
    int go[26],w,val;
    vector<int>A;
    vector<int>B;
}t[800010];
int len,n,m,aim[101000],pd[101000];
char ch[800010];
void insert(int k1,int l){
    int now=1;
    for (int i=1;i<=l;i++){
        if (t[now].go[ch[i]-'a']==0){
            t[now].go[ch[i]-'a']=++len;
            t[len].val=t[now].val+1;
        }
        now=t[now].go[ch[i]-'a'];
    }
    t[now].A.push_back(k1);
}
void insert2(int k1,int l){
    int now=1;
    for (int i=1;i<=l;i++){
        if (t[now].go[ch[i]-'a']==0){
            t[now].go[ch[i]-'a']=++len;
            t[len].val=t[now].val+1;
        }
        now=t[now].go[ch[i]-'a'];
    }
    t[now].B.push_back(k1);
}
int findans(int k){
//cout<<"dfs "<<k<<endl;
    for (int i=0;i<26;i++){
        if (t[k].go[i]==0) continue;
        findans(t[k].go[i]);
        t[k].w+=t[t[k].go[i]].w; int kk=t[k].go[i];
        if (!t[kk].A.empty()){
            int k1=t[kk].A.size(),k2=t[k].B.size();
            while (k1!=0&&k2!=0){
                aim[t[kk].A[k1-1]]=t[k].B[k2-1]; t[k].w+=t[k].val;
                t[kk].A.pop_back(); t[k].B.pop_back();
                k1--; k2--;
            }
            while (k1){
                t[k].A.push_back(t[kk].A[k1-1]);
                t[kk].A.pop_back(); k1--;
            }
        } else {
            int k1=t[kk].B.size(),k2=t[k].A.size();
            while (k1!=0&&k2!=0){
                aim[t[k].A[k2-1]]=t[kk].B[k1-1]; t[k].w+=t[k].val;
                t[kk].B.pop_back(); t[k].A.pop_back();
                k1--; k2--;
            }
            while (k1){
                t[k].B.push_back(t[kk].B[k1-1]);
                t[kk].B.pop_back(); k1--;
            }
        }
    }
    int k1=t[k].A.size(),k2=t[k].B.size();
    while (k1!=0&&k2!=0){
        aim[t[k].A[k1-1]]=t[k].B[k2-1]; t[k].w+=t[k].val;
        k1--; k2--; t[k].A.pop_back(); t[k].B.pop_back();
    }
    return t[k].w;
}
int main(){
    scanf("%d",&n,&m); len=1;
    for (int i=1;i<=n;i++){
        scanf("%s",ch+1);
        insert(i,strlen(ch+1));
    }
    for (int i=1;i<=n;i++){
        scanf("%s",ch+1);
        insert2(i,strlen(ch+1));
    }
    printf("%d\n",findans(1));
    for (int i=1;i<=n;i++) printf("%d %d\n",i,aim[i]);
    return 0;
}