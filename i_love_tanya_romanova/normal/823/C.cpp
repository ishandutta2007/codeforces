#include<bits/stdc++.h>
using namespace std;

const int N = 100031;

const int MAGIC = 1000031;

long long n,k;
int a[N];
long long ans;

vector<int> interesting;

long long solver(long long d){
	 long long ret=0;
	 for(int i=1;i<=n;i++){
	 		 long long F=a[i]/d*d;
	 		 if (F<a[i])
	 		 	F+=d;
 		 	ret+=F-a[i];
	 }
	 return ret;
}

void complete_solver(long long d){
	 long long sum=0;
	 long long total_days=0;
	 for (int i=1;i<=n;i++){
	 	 long long days_here=a[i]/d+(a[i]%d>0);
		 total_days+=days_here;
		 sum+=days_here*d-a[i];
	 }
	/* if (d==30)
	 	cout<<"@"<<sum<<endl;
	*/ if (sum>k)
	 	return;
 	//cout<<d<<" "<<sum<<" "<<total_days<<endl;
 	long long ohead=k-sum;
 	ohead/=total_days;
 	ans=max(ans,d+ohead);
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 
 cin>>n>>k;
 for (int i=1;i<=n;i++){
 	 cin>>a[i];
 }
 
 ans=-1;
 // small D
 for (int i=1;i<=MAGIC;i++){
 	 complete_solver(i);
/* 	 	 long long here=solver(i);
 	 	 if (here<k)
 	 	 	ans=max(ans,1ll*i);*/
 }

 // medium D
 
 interesting.clear();
 
 for (int i=1;i<=n;i++) // to do
 {
  for (int q=1;q*q<=a[i];q++){
  	  long long best_d=(a[i]/q+(a[i]%q>0));
  //	  cout<<"D"<<best_d<<endl;
  	  if (best_d>MAGIC)
  	  	 interesting.push_back(best_d);
  }
 }
 
 sort(interesting.begin(),interesting.end());
 for (int i=0;i<interesting.size();i++){
 	 if (i>0&&interesting[i]==interesting[i-1])
 	 	continue;
 	 	complete_solver(interesting[i]);
//	 	if (solver(interesting[i])<=k)
//	 	   ans=max(ans,0ll+interesting[i]);
 }
 /*
 // large D
 long long l,r;
 l=0;
 for (int i=1;i<=n;i++){
 	 l=max(l,0ll+a[i]);
 }
 
 r=1e12;
 
 while(l<r){
 			long long mid=l+r+1;
 			mid/=2;
 			if (solver(mid)>k)
 			   r=mid-1;
	   		   else
	   		   l=mid;
 }
 if (solver(l)<=k)
 	ans=max(ans,l);
 	*/
 cout<<ans<<endl;
 
 return 0;
}