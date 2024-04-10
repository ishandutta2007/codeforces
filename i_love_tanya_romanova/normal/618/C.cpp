/*
Malevolent criminal, I
When the vision paints my mind
Cross the invisible line
And you'll be paid in kind

Malevolent criminal, I
When the vision paints my mind
Cross the invisible line
And you'll be paid in kind
Hit it!

Criminal, this suffering
It makes me think like a criminal
The suffering, when we're alone

Criminal, this suffering
It makes me feel like a criminal
The suffering, when we're alone

Typical enough for me
That I burn inside in agony
What power will enable me
To bury my vision

The hunger coming over me
As I learn to hide the agony
To make a final remedy
To close the door once and for all!

In a world that I don't want to know
With a message that I never want to send
To be freed from all of this
I want you to quicken my end

Don't tell me I cannot go
With a wound that refuses to mend
Deliver me from all of this
I want you to quicken my end

It seems the whole experience is
Terrible and crippling
The pain is much more
Than physical, beyond belief
When we're alone

Typical enough for me
That I burn inside in agony
What power will enable me
To make this decision

Despair has fallen over me
No way to hide the agony
Embracing my calamity
To save myself once and for all!

In a world that I don't want to know
With a message that I never want to send
To be freed from all of this
I want you to quicken my end

Don't tell me I cannot go
With a wound that refuses to mend
Deliver me from all of this
I want you to quicken my end

Now you wanna know, you want a name
You wanna call me motherfucker
Now you wanna know, you want a name
You wanna say it doesn't matter

Now you wanna know, you want a name
You wanna call me motherfucker
Now you wanna know, you want a name
You wanna say it doesn't matter now!

Now, now you wanna know, now you wanna name
Now you wanna place, now you wanna time
Now you wanna know

Now, now you wanna know, now you wanna name
Now you wanna place, now you wanna time
Now you wanna know, now!

In a world that I don't want to know
With a message that I never want to send
To be freed from all of this
I want you to quicken my end

Don't tell me I cannot go
With a wound that refuses to mend
Deliver me from all of this
I want you to quicken my end

Don't say that it isn't so
I'm on a path that you'll never comprehend
Set me free from all of this
I need you to quicken my end
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 100;

using namespace std;

int n;
struct pt
{
	long long x;
	long long y;
	int id;
};

pt ans[10], nans[10];
vector<pt> pts;
vector<pt> bad_points, nbp;

bool is_part(pt a)
{
	for (int i = 0; i < 3; i++)
	{
		if (a.x == ans[i].x&&a.y == ans[i].y)
			return true;
	}
	return false;
}

long long get_area(pt a, pt b, pt c)
{
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);

}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pt temp;
		int a, b;
		cin >> a >> b;
		temp.x = a;
		temp.y = b;
		temp.id = i + 1;
		pts.push_back(temp);
	}

	ans[0] = pts[0];
	ans[1] = pts[1];
	for (int i = 2; i < pts.size(); i++)
	{
		if (get_area(ans[0], ans[1], pts[i]) == 0)
			continue;
		ans[2] = pts[i];
		break;
	}

	srand(time(0));

	vector<pt> bad_point = pts;

	while (true)
	{
		vector<pt> nbp;

		for (int i = 0; i < bad_point.size(); i++)
		{
			int flag = is_part(bad_point[i]);
			if (flag)
				continue;
			long long V1 = get_area(ans[0], ans[1], ans[2]);
			long long a1, a2, a3;
			a1 = get_area(ans[0], ans[1], bad_point[i]);
			a2 = get_area(ans[0], ans[2], bad_point[i]);
			a3 = get_area(ans[1], ans[2], bad_point[i]);
			a1 = abs(a1);
			a2 = abs(a2);
			a3 = abs(a3);
			V1 = abs(V1);
			if (a1 + a2 + a3 == V1)
			{
				nbp.push_back(bad_point[i]);
			}
		}
		if (nbp.size() == 0)
			break;
		random_shuffle(nbp.begin(), nbp.end());
		int id = rand()%nbp.size();
		int found = 0;

		for (int i = 0; i < 3&&found==0; i++)
		{
			for (int j = i + 1; j < 3 && found == 0; j++)
			{
				long long V = get_area(ans[i], ans[j], nbp[id]);
				if (V == 0)
					continue;
				found = 1;
				for (int q = 0; q < 3; q++)
					nans[q] = ans[q];
				ans[0] = nans[i];
				ans[1] = nans[j];
				ans[2] = nbp[id];
			}
		}
		bad_points = nbp;
	}

	cout << ans[0].id << " " << ans[1].id << " " << ans[2].id << endl;

	cin.get(); cin.get();
	return 0;
}