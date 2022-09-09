#include <stdio.h>
#include <iostream> 
#include <string>
#include <string.h> 
#include <vector> 
#include <math.h> 
#include <set> 
using namespace std;  
#define mp make_pair 
#define pb push_back  
typedef long long li; 
typedef long double ld;  
void solve ();  
int main () 
{ 
#ifdef _DEBUG        
freopen ("in.txt","r",stdin); 
#endif        
solve ();        
return 0; 
} 
//#define int li
string s; 
string user, host, res; 
void solve() 
{        
	cin>>s;     
	bool f=true;       
	for (int i=0; i<s.length(); i++)    
		if (s[i]=='@')                     
			f=false;      
	if (f)      
	{             
		cout<<"NO";           
		return;       
	}        
	int u=-1;   
	for (int i=0; i<s.length(); i++)      
		if ( s[i]=='@' )     
		{               
			u=i;               
			break;              
		}               
		else              
		{                    
			user.pb(s[i]);         
			if ( !(  s[i]=='_' || (s[i]<='9' && s[i]>='0' ) || ( s[i]<='z' && s[i]>='a' ) || ( s[i]<='Z' && s[i]>='A' )  ) ) 
			{                            
				cout<<"NO";                             
				return;                       
			}                
		}        
		if ( user.length()==0 || user.length()>16 )      
		{                
			cout<<"NO";                 
			return;        
		}         
		int t=s.length();    
		for (int i=u+1; i<s.length(); i++)        
			if (s[i]=='/')                 
			{                   
				t=i;                      
				break;           
			}               
			else               
			{                   
				host.pb(s[i]);            
				if ( !( s[i]=='.' ||  s[i]=='_' || (s[i]<='9' && s[i]>='0' ) || ( s[i]<='z' && s[i]>='a' ) || ( s[i]<='Z' && s[i]>='A' )  ) )                     
				{                             
					cout<<"NO";                            
					return;                        
				}                
			}        
			f=true;
			if (host.length()==0 || host.length()>32)      
			{                
				cout<<"NO";               
				return;     
			}         
			string cur;     
			for ( int i=0; i<host.length(); i++ )     
				if (host[i]=='.')            
				{                       
					if ( cur.length()==0 || cur.length()>16)          
					{                              
						cout<<"NO";                          
						return;                     
					}                        
					cur.resize(0);    
					f=false;
				}                 
				else        
				{
					cur.pb(host[i]);        
					f=true;
				}
			if ( (cur.length()==0 && !f) || cur.length()>16)       
			{              
				cout<<"NO";           
				return;       
			}         
			if (t==s.length())       
			{               
				cout<<"YES";              
				return;         
			}       
			for (int i=t+1; i<s.length(); i++)       
			{              
				res.pb (s[i]);            
				if ( !(  s[i]=='_' || (s[i]<='9' && s[i]>='0' ) || ( s[i]<='z' && s[i]>='a' ) || ( s[i]<='Z' && s[i]>='A' )  ) )      
				{                           
					cout<<"NO";                                
					return;                       
				}         
			}        
			if ( res.length()==0 || res.length()>16 )     
			{            
				cout<<"NO";     
				return;       
			}        
			cout<<"YES"; 
}