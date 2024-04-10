#include<bits/stdc++.h>
using namespace std;
inline long long Tri(long long X)
{
	return X*(X+1)/2;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long A,B;
		cin>>A>>B;
		long long Ans=Tri(A);
		A-=B;
		B++;
		long long Rem=A%B;
		A/=B;
		B-=Rem;
		Ans-=Rem*Tri(A+1);
		Ans-=B*Tri(A);
		cout<<Ans<<endl;
	}
	return 0;
}