#include<bits/stdc++.h>
using namespace std;
int w,T,n,i,p1,ww,p2;
string s;
int e3[2000000],a[2000000],b[2000000],c[2000000],e1[2000000],e2[2000000];
bool flag;
int main()
{
	cin>>T;
	for (;T;T--)
	    {
	    	cin>>n;
	    	cin>>s;
	    	for (i=1;i<=n;i++)
	    	     {
	    	     	if (s[i-1]=='0') a[i]=0;
	    	     	else a[i]=1;
	    	     	b[i]=0;c[i]=0;
				 }
			flag=true;
			p1=0;p2=0;w=0;
			for (i=1;i<=n;i++)
			    if (a[i]==1)
			        {
			           if ((p1==0)&(p2==0))
					        {
					        b[i]=1;c[i]=1;p1++;p2++;
					        }
					    else if (p1==0)
					            {
					            	if (p2>2) 
					            	    {
					            	    	if (ww>0)
					            	    	   {
					            	    	   	ww--;b[e3[ww]]=1;c[e3[ww]]=0;p1+=2;p2-=2;
											    w++;e1[w]=i;e2[w]=i;
					                          	b[i]=0;c[i]=0;p1--;p2--;
											   }
										else 	
										{
					                   b[i]=1;c[i]=1;p1++;p2++;
					                   }
										}
								else
								   {
					        b[i]=1;c[i]=1;p1++;p2++;
					        }
								}
					else
					    {
					    	w++;e1[w]=i;e2[w]=i;
					    	b[i]=0;c[i]=0;p1--;p2--;
						}
					}
			else
			     {
			     	if ((p1==0)&(p2!=0))
			     	      {
			     	      	b[i]=1;c[i]=0;p1++;p2--;
						   }
				else if ((p1!=0)&(p2==0))
				            {
				            	b[i]=0;c[i]=1;p1--;p2++;
							}
				else if ((p1==0)&(p2==0))
				           {
				           	if (w==0)
				           	  {
				           	  flag=false;break;
				              }
				            else
				               {
				               	b[e1[w]]=1;c[e2[w]]=1;
				               	w--;
				               	p1+=2;p2+=2;
				               	ww++;e3[ww]=i;
				               	b[i]=0;c[i]=1;p1--;p2++;
							   }
						   }
				else 
				     {
				     	ww++;e3[ww]=i;
				     	b[i]=0;c[i]=1;p1--;p2++;
					 }
				 }
		while ((ww>0)&((p2>0)))
		      {
		      	b[e3[ww]]=1;c[e3[ww]]=0;p1+=2;p2-=2;ww--;
			  }
		if ((p1==0)&(p2==0)&(flag==true))
		      {
		      	cout<<"YES"<<endl;
		      	for (i=1;i<=n;i++)
		      	    if (b[i]==0) cout<<")";
		    else cout<<"(";
		    cout<<endl;
		    for (i=1;i<=n;i++)
		      	    if (c[i]==0) cout<<")";
		    else cout<<"(";
		    cout<<endl;
			  }
		else cout<<"NO"<<endl;
		}
}