import sys
v = [int(x) for x in sys.stdin.read().split()]
print("YES")
for i in range(v[0]): print(1+(v[4*i+1]&1)+2*(v[4*i+2]&1))