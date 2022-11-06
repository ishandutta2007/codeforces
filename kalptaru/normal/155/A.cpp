#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	



	int max,min,current_points,total_matches;
	cin >> total_matches;
	cin >> current_points;

	max = current_points;
	min = current_points;
	int amazing_performance = 0;
	for (int i = 1; i <= (total_matches-1) ; ++i)
	{
		cin >> current_points;
		if (current_points > max)
		{
			max = current_points;
			amazing_performance++ ;
		}
		if (current_points < min)
		{
			min = current_points;
			amazing_performance++ ;
		}
	}
	cout << amazing_performance;
}