#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n;
string s;

int p[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int dif[14], fi, x, y, ans, bit[14], p1, p2;

void print(vector<int> v)
{
	cout << "? ";
	cout << v.size() << ' ';
	for(int i = 0; i <v.size(); i++)
		cout << v[i] << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	

	cin >> n >> x >> y;

	for(int i = 9; i >= 0; i--)
	{
		vector <int> v;
		for(int j = 1; j <= n; j++)
			if((j & p[i]) == p[i])
				v.push_back(j);

		if(v.size() == 0) continue;
		print(v);
		cout << endl;
		cin >> ans;

		if(ans == y || ans == (x^y))
			fi = i, dif[i] = 1;
	}

	vector <int> s;


	for(int j = 1; j <= n; j++)
		if((j & p[fi]) == p[fi])
			s.push_back(j);


	for(int i = 0; i < 10; i++)
	{
		//dbg(i);
		if(i == fi) 
		{
			p2 += p[fi];
			continue;
		}
		vector<int> v;
		for(int j = 1; j <= n; j++)
		{
			if(((j & p[fi]) == p[fi]) || ((j & p[i]) == p[i]))
				v.push_back(j);
		}

		print(v);
		cout << endl;

		cin >> ans;
		if(dif[i] == 0)
		{
			if(ans == y || ans == (x^y))
			{
				bit[i] = 0;
			}
			else 
			{
				p1 += p[i];
				p2 += p[i];
				bit[i] = 1;
			}
		}
		else {
			if(ans == y || ans == (x^y))
				p2 += p[i];
			else 
				p1 += p[i];
		}
	}
	if(p1 > p2) swap(p1, p2);
	cout << "! " << p1 << ' ' << p2 << endl;

}