n=int(input())
a={"Tetrahedron":4,"Cube":6,"Octahedron":8,"Dodecahedron":12,"Icosahedron":20}
f=0
for i in range(n):
    f+=a[input()]
print(f)