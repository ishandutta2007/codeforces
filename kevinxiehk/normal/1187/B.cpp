#include<bits/stdc++.h>
using namespace std;
int place[30][200005];
int main(){
    string s;
    int n;
    cin>>n>>s;
    for(int i=0;i<=28;i++){
        place[i][0]=0;
    }
    for(int i=0;i<s.length();i++){
        int t=s[i]-'a'+1;
        place[t][0]++;
        place[t][place[t][0]]=i+1;
    }
    string ss;
    int m,meh[30];
    cin>>m;
    for(int i=0;i<m;i++){
        memset(meh,0,sizeof(meh));
        cin>>ss;
        for(int j=0;j<ss.length();j++){
            meh[ss[j]-'a'+1]++;
        }
        int maximum=0;
        bool broke=false;
        for(int j=1;j<=26;j++){
           if(meh[j]==0)continue;
            if(meh[j]>place[j][0]){cout<<"-1"<<endl;broke=1;break;}
            maximum=max(maximum,place[j][meh[j]]);
        }
        if(!broke)cout<<maximum<<endl;
    }
    return 0;
}