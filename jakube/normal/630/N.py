from math import factorial as f

a, b, c = map(int, input().split())

d = (b*b-4*a*c)**.5
t = [(-b-d)/2/a, (-b+d)/2/a]
for i in reversed(sorted(t)): print(i)