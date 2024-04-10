#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1e6+10;
int query(string s){
    cout<<s<<endl;
    int x;
    scanf("%d",&x);
    if(x==0)exit(0);
    return x;
}
int main(){
    string s="";
    for(int i=0;i<300;i++)s.push_back('a');
    int a=300-query(s);
    s="";
    for(int i=0;i<a;i++)s.push_back('a');
    int b;
    if(a)b=query(s);
    else{
        for(int i=0;i<300;i++)s.push_back('b');
        b=300-query(s);
        s="";
        for(int i=0;i<b;i++)s.push_back('b');
        query(s);
        return 0;
    }
    int lv=b;
    string bas="";
    for(int i=0;i<a+b;i++){
        bas.push_back('b');
        s=bas;
        for(int i=bas.size();i<a+b;i++){
            s.push_back('a');
        }
        int nxt=query(s);
        if(nxt<lv)lv--;
        else bas.back()='a';
    }
    cout<<bas<<endl;
}