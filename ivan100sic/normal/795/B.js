var line = readline().split(' ');
var n = parseInt(line[0]);
var m = parseInt(line[1]);
var d = parseInt(line[2]);

var i, j, k, a, b, c, w;

a = [];

for (i=0; i<n; i++) {
	line = readline().split(' ');
	c = parseInt(line[0]);
	w = parseInt(line[1]);

	a.push({c: c, w: w});
}

b = [];

for (i=0; i<m; i++) {
	line = readline().split(' ');
	c = parseInt(line[0]);
	w = parseInt(line[1]);

	b.push({c: c, w: w});
}

function cmp(u, v) {
	if (u.c != v.c) {
		return -1 * (u.c - v.c);
	}

	return u.w - v.w;
}

a.sort(cmp);
b.sort(cmp);

i = 1;
j = 0;

var sirina = a[0].w;
var zbir = a[0].c;
var sol = 0;

// dodaj
while (j < m && sirina + b[j].w <= d) {
	sirina += b[j].w;
	zbir += b[j].c;
	j += 1;

	if (zbir > sol) {
		sol = zbir;
	}
}

for (i=1; i<n; i++) {
	sirina += a[i].w;
	zbir += a[i].c;

	while (sirina > d && j > 0) {
		j--;
		sirina -= b[j].w;
		zbir -= b[j].c;
	}

	if (zbir > sol && j > 0) {
		sol = zbir;
	}
}

print(sol);