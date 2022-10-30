#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct solver{
	private:
		string first,second,third;
		string patterns[3];
		char winner;
	public:
		solver()
		{
			winner='?';
			patterns[0]="rock",patterns[1]="scissors",patterns[2]="paper";
		}
		inline void scan()
		{
			cin>>first>>second>>third; 
		}
		inline void work()
		{
			for(register int i=0;i<3;i++)
			{
				if(first==patterns[i]&&second==patterns[(i+1)%3]&&third==second)
				{
					winner='F';
				}
			}
			for(register int i=0;i<3;i++)
			{
				if(second==patterns[i]&&first==patterns[(i+1)%3]&&third==first)
				{
					winner='M';
				}
			}
			for(register int i=0;i<3;i++)
			{
				if(third==patterns[i]&&first==patterns[(i+1)%3]&&first==second)
				{
					winner='S';
				}
			}
		}
		inline void print()
		{
			cout<<winner<<endl;
		}
};
solver sol;
int main()
{
	sol.scan();
	sol.work();
	sol.print();
}