#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,m,m1,k,p,aa[12345],bb[12234],cc[12345],kol;

string s[123455],x,y,ss[123];

int chek(string x, string y, int zz1, int zz2){
	string h1="",h2="";
	int p=0;
    for (int i=0; i<x.length(); i++) {
    	if (x[i]=='-') p++;
    	if (p==0) h1+=x[i];   
    	if (p==2) h2+=x[i];	
    	if (p==1) p=2;
    }
    for (int i=0; i<n; i++) {
    	if (s[i]==h1) zz1=i; 
    	if (s[i]==h2) zz2=i;
    }
    
	string a="",b="";
    p=0;
    for (int i=0; i<y.length(); i++) {
    	if (y[i]==':') p++;
    	if (p==0) a+=y[i];  else 
    	if (p==2) b+=y[i];	
    	if (p==1) p=2;
    }
    int g1=0, g2=0, k=1;
    for (int i=a.length()-1; i>=0; i--)  {
    	g1+=(a[i]-'0')*k;
    	k*=10;
    }
    k=1;
    for (int i=b.length()-1; i>=0; i--)  {
    	g2+=(b[i]-'0')*k;
    	k*=10;
    }
    if (g1>g2) aa[zz1]+=3; else 
   		if (g1<g2) aa[zz2]+=3; else 
    		{aa[zz1]++; aa[zz2]++;}
    bb[zz1]+=(g1-g2);
    bb[zz2]+=(g2-g1);
    
    cc[zz1]+=g1;
    cc[zz2]+=g2;

    return 0;
    
}


int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>s[i];
		m+=i+1;
	}
	m-=n;
	for (int i=0; i<m; i++)    {
	    cin>>x>>y;
		chek(x,y,m1,p);
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (aa[i]>aa[j]) {swap(aa[i],aa[j]); swap(s[i],s[j]); swap(bb[i],bb[j]); swap(cc[i],cc[j]);} else 
				if (aa[i]==aa[j]) {
					if (bb[i]>bb[j]) {swap(bb[i],bb[j]); swap(s[i],s[j]);swap(cc[i],cc[j]);} else 
						if (bb[i]==bb[j]) {
							if (cc[i]>cc[j]) {swap(cc[i],cc[j]); swap(s[i],s[j]); }
						}
				} 


	//for (int i=0; i<n; i++)
	//	cout<<s[i]<<" "<<aa[i]<<" "<<bb[i]<<" "<<cc[i]<<endl;
	
	for (int i=0; i<n/2; i++)
		ss[i]=s[i];
	n/=2;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (ss[i]<ss[j]) swap(ss[i],ss[j]); 
	
	for (int i=0; i<n; i++)
		cout<<ss[i]<<endl;
	return 0;
}