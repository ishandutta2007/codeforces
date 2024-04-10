#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct PQtree{
    int type,father;
    vector<int>child;
}t[2010];
int n,pd[2010],w[2010],size[2010],in[5010],B[2010],W[3]={0,2,1},ans[2010],C[600][600],len,kk;
//in S
//pd Reduce012
//w ReduceS
//size ReduceReduce 
vector<int>rem,A;
char getin(){
    char ch=getchar(); while (ch<'0'||ch>'9') ch=getchar(); return ch;
}
int getnext(){
    int k1=rem[(rem.size())-1]; rem.pop_back();
    t[k1].child.clear(); t[k1].type=0; t[k1].father=0;
    //cout<<"new "<<k1<<endl; 
    return k1;
}
void reverse(int k){
    vector<int>k1;
    for (int i=0;i<t[k].child.size();i++) k1.push_back(t[k].child[i]); t[k].child.clear();
    for (int i=(k1.size())-1;i>=0;i--) t[k].child.push_back(k1[i]);
}
void change(int k1,int k2,int k3){
    if (k1==0) return;
    for (int i=0;i<t[k1].child.size();i++) if (t[k1].child[i]==k2){t[k1].child[i]=k3; return;}
}
int reduce(){
    memset(B,0x00,sizeof B);
    memset(size,0x00,sizeof size);
    memset(w,0x00,sizeof w);
    memset(pd,0xff,sizeof pd);
    queue<int>Q;
    for (int i=1;i<=n;i++){
        Q.push(i); pd[i]=in[i]; w[i]=in[i];
    }
    while (!Q.empty()){
        int k=Q.front(); Q.pop(); int flag=0;
        if (w[k]==A.size()) flag=1;//cout<<"reduce "<<kk<<" "<<k<<" "<<pd[k]<<" "<<flag<<" "<<w[k]<<endl;
        if (pd[k]==2){
            //for (int i=0;i<t[k].child.size();i++) cout<<t[k].child[i]<<" "; cout<<endl;
            vector<int>C[3];
            for (int i=0;i<t[k].child.size();i++){
                int j=t[k].child[i]; C[pd[j]].push_back(j);
            }
            if (t[k].type==1){ //P0P1 
                if (C[2].size()==0){
                    if (flag==1){
                        if (C[1].size()>1){ //P1
                            int k1=getnext(); 
                            for (int i=0;i<C[1].size();i++){
                                t[k1].child.push_back(C[1][i]); t[C[1][i]].father=k1;
                            }
                            t[k1].father=k; t[k].child.clear(); t[k1].type=1; pd[k1]=1;
                            for (int i=0;i<C[0].size();i++) t[k].child.push_back(C[0][i]);
                            t[k].child.push_back(k1);
                        }
                    } else { //P2
                        t[k].type=2; t[k].child.clear();
                        if (C[0].size()>1){
                            int k1=getnext(); t[k1].father=k; t[k].child.push_back(k1); t[k1].type=1; pd[k1]=0;
                            for (int i=0;i<C[0].size();i++) {
                                t[k1].child.push_back(C[0][i]); t[C[0][i]].father=k1;
                            }
                        } else if (C[0].size()) t[k].child.push_back(C[0][0]);
                        if (C[1].size()>1){
                            int k1=getnext(); t[k1].father=k; t[k].child.push_back(k1); t[k1].type=1; pd[k1]=1;
                            for (int i=0;i<C[1].size();i++) {
                                t[k1].child.push_back(C[1][i]); t[C[1][i]].father=k1;
                            }
                        } else if (C[1].size()) t[k].child.push_back(C[1][0]);
                    }
                } else if (C[2].size()==1){
                    if (flag==1){ //P4
                        t[k].child.clear(); 
                        if (C[1].size()==1){
                            t[C[2][0]].child.push_back(C[1][0]); t[C[1][0]].father=C[2][0];
                            for (int i=0;i<C[0].size();i++) t[k].child.push_back(C[0][i]); t[k].child.push_back(C[2][0]);
                        } else if (C[1].size()){
                            int k1=getnext(),k2=C[2][0]; t[k1].type=1; t[k1].father=k2; pd[k1]=1;
                            for (int i=0;i<C[1].size();i++) {t[k1].child.push_back(C[1][i]); t[C[1][i]].father=k1;}
                            t[k2].child.push_back(k1);
                            for (int i=0;i<C[0].size();i++) t[k].child.push_back(C[0][i]); t[k].child.push_back(k2);
                        }
                        if (t[k].child.size()==1){
                            t[t[k].child[0]].father=t[k].father; change(t[k].father,k,t[k].child[0]); rem.push_back(k);
                        }
                    } else { //P5
                    //  cout<<"fuck"<<endl;
                        t[k].child.clear(); t[k].type=2;
                        if (C[0].size()==1) t[k].child.push_back(C[0][0]);
                        else if (C[0].size()){
                            int k1=getnext(); t[k1].type=1; t[k1].father=k; pd[k1]=0;
                            for (int i=0;i<C[0].size();i++){
                                t[k1].child.push_back(C[0][i]); t[C[0][i]].father=k1;
                            }
                            t[k].child.push_back(k1);
                        }
                        int k2=C[2][0];
                        for (int i=0;i<t[k2].child.size();i++){t[k].child.push_back(t[k2].child[i]); t[t[k2].child[i]].father=k;}
                        if (C[1].size()==1) t[k].child.push_back(C[1][0]);
                        else if (C[1].size()){
                            int k1=getnext(); t[k1].type=1; t[k1].father=k; pd[k1]=1;
                            for (int i=0;i<C[1].size();i++){
                                t[k1].child.push_back(C[1][i]); t[C[1][i]].father=k1;
                            }
                            t[k].child.push_back(k1);
                        }
                        rem.push_back(k2); 
                    //  cout<<t[12].child.size()<<endl;
                    } 
                }else if (C[2].size()==2){ //P6 
                    if (flag==0) return 0; //cout<<"fuck"<<endl;
                    t[k].child.clear(); 
                    for (int i=0;i<C[0].size();i++) t[k].child.push_back(C[0][i]);
                    int k1=getnext(); int k2=C[2][0]; t[k1].type=2; t[k1].father=k;
                    for (int i=0;i<t[k2].child.size();i++){t[k1].child.push_back(t[k2].child[i]); t[t[k2].child[i]].father=k1;}
                    rem.push_back(k2); pd[k1]=2;
                    if (C[1].size()==1){
                        t[k1].child.push_back(C[1][0]); t[C[1][0]].father=k1;
                    }else if (C[1].size()){
                        int k3=getnext(); t[k3].type=1; t[k3].father=k1; pd[k3]=1;
                        for (int i=0;i<C[1].size();i++){
                            t[k3].child.push_back(C[1][i]); t[C[1][i]].father=k3;
                        }
                        t[k1].child.push_back(k3);
                    }
                    t[k].child.push_back(k1);
                    k2=C[2][1];
                    for (int i=(t[k2].child.size())-1;i>=0;i--){t[k1].child.push_back(t[k2].child[i]); t[t[k2].child[i]].father=k1;}
                    rem.push_back(k2);
                    if (t[k].child.size()==1){
                        t[k1].father=t[k].father; change(t[k].father,k,k1); rem.push_back(k);
                    }
                } else return 0;
            } else { //Q0Q1 
                int now=0,flag2=0;
                for (int i=0;i<t[k].child.size();i++){
                    int j=t[k].child[i]; if (W[pd[j]]<now) {flag2=1; break;}
                    now=W[pd[j]];
                }
                int flag3=0; now=2;
                for (int i=0;i<t[k].child.size();i++){
                    int j=t[k].child[i]; if (W[pd[j]]>now) {flag3=1; break;}
                    now=W[pd[j]];
                }
                if ((flag2==0||flag3==0)&&C[2].size()==1){ //Q2
                    if (flag3==0){
                        reverse(k);
                        C[0].clear(); C[1].clear(); C[2].clear();
                        for (int i=0;i<t[k].child.size();i++){
                            int j=t[k].child[i]; C[pd[j]].push_back(j);
                        }
                    }   
                    t[k].child.clear();
                    for (int i=0;i<C[0].size();i++) t[k].child.push_back(C[0][i]);
                    int k2=C[2][0];
                    for (int i=0;i<t[k2].child.size();i++){
                        t[k].child.push_back(t[k2].child[i]); t[t[k2].child[i]].father=k;
                    }
                    rem.push_back(k2);
                    for (int i=0;i<C[1].size();i++) t[k].child.push_back(C[1][i]);
                } else if (C[2].size()<=2&&C[2].size()>=1){ //Q3
                    if (flag==0) return 0;
                    int two1=-1,two2=-1;
                    for (int i=0;i<t[k].child.size();i++){
                        int j=t[k].child[i];
                        if (pd[j]==2){
                            if (two1!=-1) two2=i; else two1=i;
                        }
                    }
                    if (C[2].size()==2){
                    /*  cout<<C[2][0]<<" "<<C[2][1]<<endl;
                        for (int i=0;i<t[k].child.size();i++) cout<<pd[t[k].child[i]]<<" "; cout<<endl;
                        cout<<two1<<" "<<two2<<endl;
                        cout<<"fuck"<<endl;*/
                        for (int i=0;i<two1;i++){
                            int j=t[k].child[i];
                            if (pd[j]!=0) return 0;
                        }
                        for (int i=two1+1;i<two2;i++){
                            int j=t[k].child[i];
                            if (pd[j]!=1) return 0;
                        }
                        for (int i=two2+1;i<t[k].child.size();i++){
                            int j=t[k].child[i];
                            if (pd[j]!=0) return 0;
                        }
                        reverse(C[2][1]);
                        t[k].child.clear();
                        for (int i=0;i<two1;i++) t[k].child.push_back(C[0][i]);
                        int k2=C[2][0];
                        for (int i=0;i<t[k2].child.size();i++){
                            t[k].child.push_back(t[k2].child[i]); t[t[k2].child[i]].father=k;
                        }
                        rem.push_back(k2);
                        for (int i=0;i<C[1].size();i++) t[k].child.push_back(C[1][i]);
                        k2=C[2][1];
                        for (int i=0;i<t[k2].child.size();i++){
                            t[k].child.push_back(t[k2].child[i]); t[t[k2].child[i]].father=k;
                        }
                        rem.push_back(k2);
                        for (int i=two1;i<C[0].size();i++) t[k].child.push_back(C[0][i]);
                    } else {
                //      cout<<"fuck "<<two1<<endl;
                        int flag4=0;
                        for (int i=0;i<two1;i++){
                            int k1=t[k].child[i]; if (pd[k1]==1){flag4=1; break;}
                        }
                        if (flag4){reverse(k); two1=(t[k].child.size())-two1-1;}
                        for (int i=0;i<two1;i++){
                            int k1=t[k].child[i]; if (pd[k1]) return 0;
                        }
                        int now=1;
                        for (int i=two1+1;i<t[k].child.size();i++){
                            int k1=t[k].child[i]; if (pd[k1]>now) return 0;
                            now=pd[k1];
                        }
                        C[0].clear(); C[1].clear(); C[2].clear();
                        for (int i=0;i<t[k].child.size();i++){
                            int j=t[k].child[i]; C[pd[j]].push_back(j);
                        }
                        t[k].child.clear();
                        for (int i=0;i<two1;i++) t[k].child.push_back(C[0][i]);
                        int k2=C[2][0];
                        for (int i=0;i<t[k2].child.size();i++){
                            t[k].child.push_back(t[k2].child[i]); t[t[k2].child[i]].father=k;
                        }
                        rem.push_back(k2);
                        for (int i=0;i<C[1].size();i++) t[k].child.push_back(C[1][i]);
                        for (int i=two1;i<C[0].size();i++) t[k].child.push_back(C[0][i]);
                    }
                } else if (C[2].size()==0){
                //  cout<<"fuck"<<" "<<flag<<endl;
                    if (pd[t[k].child[0]]==1) reverse(k);
                    int k1=t[k].child.size();
                    for (int i=0;i<t[k].child.size();i++){
                        int k2=t[k].child[i]; if (pd[k2]==1){k1=i; break;}
                    }
                    int k3=t[k].child.size();
                    for (int i=k1;i<t[k].child.size();i++){
                        int k2=t[k].child[i]; if (pd[k2]==0){k3=i; break;}
                    }
                    if (flag==0&&k3!=t[k].child.size()) return 0;
                    if (flag==1)
                //  cout<<k3<<endl;
                        for (int i=k3;i<t[k].child.size();i++){
                            int k2=t[k].child[i]; if (pd[k2]==1) return 0;
                        }
                } else return 0;
            }
        }
        //update
        if (flag) return 1;
        int k1=t[k].father; size[k1]++; w[k1]+=w[k];
        if (pd[k1]==-1) pd[k1]=pd[k]; else if (pd[k1]!=pd[k]) pd[k1]=2;
        if (size[k1]==t[k1].child.size()) Q.push(k1);
    }
}
void print(int k){
    if (t[k].type==0){ans[++len]=k; return;}
    for (int i=0;i<t[k].child.size();i++) print(t[k].child[i]);
}
int main(){
//  freopen("data.in","r",stdin);
//  freopen("data.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        t[i].type=0; t[i].father=n+1; t[i].child.clear(); t[n+1].child.push_back(i);
    }
    t[n+1].type=1; 
    for (int i=2000;i>n+1;i--) rem.push_back(i);
    for (int i=1;i<=n;i++){
        memset(in,0x00,sizeof in); A.clear();
        for (int j=1;j<=n;j++){
            char ch=getin(); C[i][j]=ch-'0';
            if (ch=='1') {A.push_back(j); in[j]=1;}
        }
        kk=i;
        if (reduce()==0){cout<<"NO"<<endl; return 0;}
        /*for (int j=n+1;t[j].type;j++){
            cout<<j<<" "<<t[j].type<<" "<<t[j].father<<" "<<t[j].child.size()<<endl;
            for (int k=0;k<t[j].child.size();k++) cout<<t[j].child[k]<<" "; cout<<endl;
        }
        int root=1;
        while (t[root].father) root=t[root].father; cout<<root<<endl;*/
    }
    int root=1;
    while (t[root].father) root=t[root].father;
    cout<<"YES"<<endl; print(root);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%d",C[i][ans[j]]); cout<<endl;
    }
    return 0;
}