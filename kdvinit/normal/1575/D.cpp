#include <iostream>
        #include <cstring>
        #include <vector>
        #include <set>
        #include <bits/stdc++.h>
        #include <stdlib.h>
        #include <math.h>
        #include <queue>
        #include <iomanip>
        #include <tuple>
        #define MOD 1000000007
        #include <chrono>
        #define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
	//	#define int long long
		#define YES cout<<"YES"<<endl;
		#define NO cout<<"NO"<<endl;
		#define nw cout<<endl;
		#define zero(a) memset(a,0,sizeof(a));
		#define all(a) a.begin(),a.end();
		#define one(a) memset(a,1,sizeof(a));
		#define sz(a) (int) a.size();
		#pragma GCC optimize("O2")
        using namespace std;
        using namespace std::chrono;
        
  int mul(int a,int b)
  {
	  return (a*b)%MOD;
  }
  
  int modinv(int a)
  {
	  int b=MOD-2;
	  int A=a;
	  int c=1;
	  for(int i=0;i<62;i++)
	  {
		  if((long long)1<<i&(b))
		  {
			  c=mul(c,A);
		  }
		  A*=A;
		  A%=MOD;
	  }
	  return c;
  }
  
  
  int mul(int a,int b,int c)
  {
	  return mul(mul(a,b),c);
  }   
  
 
  
int nCr(int n,int r)
{
	int num=1;
	int den=1;
	int k=max(r,n-r);
	for(int i=k+1;i<=n;i++)
	{
		num=mul(num,i);
	}
	for(int i=1;i<=n-k;i++)
	{
		den=mul(den,i);
	}
	return mul(num,modinv(den));
}
		
 
			
int gcd(int x,int y)
{
	if(y>x)
	{
		return gcd(y,x);
	}
	else if(y==0)
	{
		return x;
	}
	else
	{
		return gcd(y,x%y);
	}
}	


string toVec(int a)
{

		string temp=std::to_string(a);
		
		
		reverse(temp.begin(),temp.end());
		return temp;
	
}


bool update(string &A, string &B,int i)
{
	if(A[i]==B[i])
	{
		return true;
	}
	else if(A[i]=='_')
	{
		return true;
	}
	else if(A[i]=='X')
	{
		for(int j=i;j<A.size();j++)
		{
			if(A[j]=='X')
			{
				A[j]=B[i];
			}
		}
		return true;
	}
	return false;
}
				

int check(string A,string B)
{
		
	if(A.size()!=B.size())
	{
		return 0;
	}
	else
	{
		for(int i=0;i<A.size();i++)
		{
			if(update(A,B,i)==false)
			{
				return 0;
			}
		}
		return 1;
	}
}
		
		
		
	
 
int32_t main() {
   boost;
   
   string A;
   cin>>A;
   
   int val=0;
   int start=0;
   reverse(A.begin(),A.end());
   while(start<=1e8)
   {
	   string curr=toVec(start);
	   val+=check(A,curr);
	   start+=25;
	   
   }
	   
	cout<<val<<endl;
  
   
   
   
   
   return 0;
}