
#include  <bits/stdc++.h> 
 
using namespace std;

#define MAXN 1123456
#define pb push_back

int s;

bool can(string &a, string &b){
    int freqa[27];
    int freqb[27];
    int diff=0;
    for(int i=0;i<27;i++){
        freqa[i]=0;
        freqb[i]=0;
    }
    for(int i=0;i<s;i++){
        if(a[i]!=b[i])diff++;
        freqa[a[i]-'a']++;
        freqb[b[i]-'a']++;
    }
    bool has2=0;
    for(int i=0;i<27;i++){
        if(freqa[i]!=freqb[i])return 0;
        if(freqa[i]>=2)has2=1;
    }
    if(diff==2 || (has2&&diff==0))return 1;
    return 0;
}

vector<string> anss(string &a,string &b){
    //cout<<"entrou em ans com "<<a<<" "<<b<<endl;
    vector<int> diff;
    vector<string> resp;
    for(int i=0;i<s;i++){
        if(a[i]!=b[i]){
            diff.pb(i);
        }
    }
    string par = a;
    if(diff.size()==4 || diff.size()==3){
        vector<int> diff2=diff;
        //for(int i=0;i<diff2.size();i++)cout<<diff2[i]<<" ";
        //cout<<endl;
        do{
            next_permutation(diff2.begin(),diff2.end());
            for(int i=0;i<diff2.size();i++)par[diff[i]]=a[diff2[i]];
            //cout<<par<<endl;
            if(can(a,par)&&can(b,par))resp.pb(par);
        }while(diff2!=diff);
        return resp;
    }
    if(diff.size()==2){
        for(int i=0;i<s;i++){
            //cout<<i<<endl;
            vector<int> diff2=diff;
            diff2.pb(i);
            diff.pb(i);
            do{
                next_permutation(diff2.begin(),diff2.end());
                for(int j=0;j<diff2.size();j++)par[diff[j]]=a[diff2[j]];
                if(can(a,par)&&can(b,par))resp.pb(par);
            }while(diff2!=diff);
            diff.pop_back();
        }
        return resp;
    }
    vector<string> nada;
    return nada;
}

vector<string> intersect(vector<string> &a,vector<string> &b){
    set<string> sa;
    set<string> sb;
    vector<string> resp;
    for(int i=0;i<a.size();i++){
        sa.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){
        sb.insert(b[i]);
    }
    while(sa.size()>0){
        if(sb.find(*sa.begin())!=sb.end()){
            resp.pb(*sa.begin());
        }
        sa.erase(*sa.begin());
    }
    return resp;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n>>s;
    set<string> sts;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        sts.insert(t);
    }
    if(sts.size()==1){
        string resp=*sts.begin();
        swap(resp[0],resp[1]);
        cout<<resp<<endl;
        return 0;
    }
    vector<string> respar;
    string fir=*sts.begin();
    sts.erase(*sts.begin());
    string sec=*sts.begin();
    sts.erase(*sts.begin());
    //cout<<"oi"<<endl;
    respar=anss(fir,sec);
    string last=sec;
    //cout<<"oi"<<endl;
    while(sts.size()>0){
        //for(int i=0;i<respar.size();i++){
        //    cout<<respar[i]<<" ";
        //}
        //cout<<endl;
        string at=*sts.begin();
        vector<string> anspar=anss(last,at);
        respar=intersect(respar,anspar);
        last=*sts.begin();
        sts.erase(*sts.begin());
    }
    if(respar.size()==0)cout<<-1<<endl;
    else cout<<respar[0]<<endl;

    return 0;
}