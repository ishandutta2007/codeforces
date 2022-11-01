mp = {
'Tetrahedron': 4,
'Cube': 6,
'Octahedron': 8,
'Dodecahedron': 12,
'Icosahedron': 20,
}
n = int(input())
ans = 0
for i in range(n):
	s = input().strip()
	ans += mp[s]
print(ans)