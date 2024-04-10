#include <bits/stdc++.h>

using namespace std;
int n,i,j,sa,cnt,onn,sit;string s[100001];bool a[100001][26],no;vector <vector<bool>>b;vector<string>s2;
void add(string ss)
{
s2.push_back(ss);
b.push_back(vector<bool>(26));
for(int kh=0;kh<=25;kh++)b[sa][kh]=a[i][kh];


}
bool yes(string ss,int w,int q){

    int siz=ss.size();
    if(siz>26)return false;

   if(w==j) {for(int qq=q;ss[qq];qq++){if(b[w][int(ss[qq])-97])return false;
      b[w][int(ss[qq])-97]=true;}}
      else for(int qq=q;ss[qq];qq++){if(a[w][int(ss[qq])-97])return false;}
      for(int kh=0;kh<=25;kh++)a[i][kh]|=b[j][kh];

     s[i]=s2[j];s2.erase(s2.begin()+j); b.erase(b.begin()+j);j--,cnt--,sa--;
      return true;
                                 }
bool check(string x){
    int siz=x.size();
    if(siz>26)return false;
    for(int r=0;r<siz;r++){if(a[i][int(x[r])-97])return false;a[i][int(x[r])-97]=true;}
    return true;
}
int comp(string x,string y)
{  string one=x,two=y,chh;int chek,si,osi,tsi;
   if(!(b[j][int(x[0])-97]))one=x,two=y;
   if(!(a[i][int(y[0])-97]))one=y,two=x;
   osi=one.size(),tsi=two.size();

   for(int z=0;z<osi;z++)
   {
       if(one[z]==two[0]){si=min(osi-z,tsi);chek=memcmp(&one[z],&two[0],si);
       if(chek!=0)return 0;
       if(chek==0)
       {  if(s2[j]==one)onn=true;else onn=false;
           if(tsi>osi-z)
            for(int k=si;k<tsi;k++)one+=two[k];
            s2[j]=one;if(onn){if(!yes(one,j,osi))return 0;}
                             else if(!yes(one,i,osi))return 0;
                                return 1;
       }

       }

   }for(int kh=0;kh<=25;kh++) if(a[i][kh]==b[j][kh]&&b[j][kh]!=false)return 0;return 1;
}
int main()
{
    cin>>n;
   for(i=0;i<n;i++){cin>>s[i];if(!check(s[i]))no=true;}

   if(no)return cout<<"NO",0;
   i=0;
   add(s[0]);
   for( i=1;i<n;i++)
   {    sa=s2.size(),sit;
       for( j=0;j<sa;j++){
            sit=comp(s[i],s2[j]);
       if(sit==0)return cout<<"NO",0;
       }

       add(s[i]);

   }

   sort(s2.begin(),s2.end());
   for(int i=0;i<s2.size();i++)cout<<s2[i];


    return 0;
}