#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  string name[100],kind[100];
  int a[100],b[100],c[100],s[100];
  int S=0;
  for(int i=0;i<n;i++){
    cin>>name[i]>>kind[i]>>a[i]>>b[i]>>c[i]>>s[i];
    S+=s[i];
  }
  int k;
  scanf("%d",&k);
  if(S==k){
    //return 0;
    int p[100]={0};
    static string Name[1000],bl[1000];
    for(int i=0;i<k;i++){
      string s;
      int K;
      cin>>Name[i]>>s>>K>>bl[i];
      for(int j=0;j<n;j++){
	if(name[j]==bl[i]){
	  p[j]++;
	  if(s[0]=='g'){
	    a[j]+=K;
	  }
	  if(s[0]=='s'){
	    b[j]+=K;
	  }
	  if(s[0]=='p'){
	    c[j]+=K;
	  }
	  break;
	}
      }
    }
    //return 0;
    int A=-1,B=-1,C=-1,AA,BB,CC;
    for(int i=0;i<n;i++){
      if(kind[i][0]=='w'&&A<a[i]){
	A=a[i];
	AA=i;
      }
      if(kind[i][0]=='a'&&B<b[i]){
	B=b[i];
	BB=i;
      }
      if(kind[i][0]=='o'&&C<c[i]){
	C=c[i];
	CC=i;
      }
    }
    //return 0;
    cout<<name[AA]<<' '<<p[AA];
    for(int j=0;j<k;j++){
      if(bl[j]==name[AA]){
	cout<<' '<<Name[j];
      }
    }
    cout<<'\n';
    cout<<name[BB]<<' '<<p[BB];
    for(int j=0;j<k;j++){
      if(bl[j]==name[BB]){
	cout<<' '<<Name[j];
      }
    }
    cout<<'\n';
    cout<<name[CC]<<' '<<p[CC];
    for(int j=0;j<k;j++){
      if(bl[j]==name[CC]){
	cout<<' '<<Name[j];
      }
    }
    cout<<'\n';
  }
  else{
    vector<pair<int,string> > gl,se,ph;
    for(int i=0;i<k;i++){
      string Name,Kind,bl;
      int K;
      cin>>Name>>Kind>>K>>bl;
      if(Kind[0]=='g'){
	gl.push_back(make_pair(K,Name));
      }
      if(Kind[0]=='s'){
	se.push_back(make_pair(K,Name));
      }
      if(Kind[0]=='p'){
	ph.push_back(make_pair(K,Name));
      }
    }
    sort(gl.begin(),gl.end());
    sort(se.begin(),se.end());
    sort(ph.begin(),ph.end());
    //return 0;
    for(int i=0;i<n;i++){
      if(kind[i][0]=='w'){
	for(int j=0;j<s[i]&&j<gl.size();j++){
	  a[i]+=gl[gl.size()-j-1].first;
	}
      }
      if(kind[i][0]=='a'){
	for(int j=0;j<s[i]&&j<se.size();j++){
	  b[i]+=se[se.size()-j-1].first;
	}
      }
      if(kind[i][0]=='o'){
	for(int j=0;j<s[i]&&j<ph.size();j++){
	  c[i]+=ph[ph.size()-j-1].first;
	}
      }
    }
    int A=-1,B=-1,C=-1,AA,BB,CC;
    for(int i=0;i<n;i++){
      if(kind[i][0]=='w'&&A<a[i]){
	A=a[i];
	AA=i;
      }
      if(kind[i][0]=='a'&&B<b[i]){
	B=b[i];
	BB=i;
      }
      if(kind[i][0]=='o'&&C<c[i]){
	C=c[i];
	CC=i;
      }
    }
    vector<string> As,Bs,Cs;
    for(int j=0;j<s[AA]&&j<gl.size();j++){
      As.push_back(gl[gl.size()-j-1].second);
    }
    for(int j=0;j<s[BB]&&j<se.size();j++){
      Bs.push_back(se[se.size()-j-1].second);
    }
    for(int j=0;j<s[CC]&&j<ph.size();j++){
      Cs.push_back(ph[ph.size()-j-1].second);
    }
    //return 0;
    //printf("%d %d %d %d %d %d\n",s[AA],s[BB],s[CC],gl.size(),se.size(),ph.size());
    for(int j=0;j<(int)gl.size()-s[AA];j++){
      if(Bs.size()<s[BB]){
	Bs.push_back(gl[j].second);
      }
      else if(Cs.size()<s[CC]){
	Cs.push_back(gl[j].second);
      }
    }
    for(int j=0;j<(int)se.size()-s[BB];j++){
      if(As.size()<s[AA]){
	As.push_back(se[j].second);
      }
      else if(Cs.size()<s[CC]){
	Cs.push_back(se[j].second);
      }
    }
    for(int j=0;j<(int)ph.size()-s[CC];j++){
      if(Bs.size()<s[BB]){
	Bs.push_back(ph[j].second);
      }
      else if(As.size()<s[AA]){
	As.push_back(ph[j].second);
      }
    }
    //return 0;
    cout<<name[AA]<<' '<<As.size();
    for(int i=0;i<As.size();i++){
      cout<<' '<<As[i];
    }
    cout<<'\n';
    cout<<name[BB]<<' '<<Bs.size();
    for(int i=0;i<Bs.size();i++){
      cout<<' '<<Bs[i];
    }
    cout<<'\n';
    cout<<name[CC]<<' '<<Cs.size();
    for(int i=0;i<Cs.size();i++){
      cout<<' '<<Cs[i];
    }
    cout<<'\n';
  }
}