module main;

import std.stdio, std.string, std.conv, std.algorithm, std.numeric;
import std.range, std.array, std.math, std.typecons, std.container, core.bitop;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int q1 = 0, q2 = 0, q3 = 0;
	for (int i = 1; i <= 6; i++)
	{
	    if (abs(a - i) < abs(b - i))
	        q1++;
	    if (abs(a - i) == abs(b - i))
	        q2++;
	    if (abs(a - i) > abs(b - i))
	        q3++;
	}
    printf("%d %d %d", q1, q2, q3);
	return 0;
}