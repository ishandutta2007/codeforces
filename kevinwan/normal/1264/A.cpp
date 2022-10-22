#include<bits/stdc++.h>
using namespace std;
int main(){
    int tcc;
    scanf("%d",&tcc);
    while(tcc--){
        int n;
        scanf("%d",&n);
        int ln=0x3f3f3f3f;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x==ln)v[v.size()-1]++;
            else v.push_back(1),ln=x;
        }
        int g=v[0],s=0,b=0;
        int i;
        for(i=1;i<v.size()&&s<=g;i++)s+=v[i];
        for(;i<v.size();i++){
            if((g+s+b+v[i])*2>n)break;
            b+=v[i];
        }
        if(s<=g||b<=g||(g+s+b)*2>n)g=s=b=0;
        printf("%d %d %d\n",g,s,b);
    }
}