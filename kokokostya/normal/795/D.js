var temp = readline().split(' ').map(Number);
var n = temp[0];
var l = temp[1];
var r = temp[2];
//print(n)
//print(l)
//print(r)
var fr = readline().split(' ').map(Number);
var sc = readline().split(' ').map(Number);
l -= 1;
r -= 1;
var ch = 1;
for (var i = 0; i < l; i++) {
	if (fr[i] != sc[i])	{
		ch = 0;
		//exit(0);
	}
}
for (var i = r + 1; i < n; i++) {
	if (fr[i] != sc[i]) {
		ch = 0;
		//exit(0);
	}
}
var c1 = [];
var c2 = [];
for (var i = l; i <= r; i++) {
	c1.push(fr[i]);
	c2.push(sc[i]);
}
c1.sort();
c2.sort();
for (var i = l; i <= r; i++) {
	if (c1[i - l] != c2[i - l]) {
		ch = 0;
		//exit(0);
	}
}
if (ch == 0)
	print("LIE");
else
	print("TRUTH");