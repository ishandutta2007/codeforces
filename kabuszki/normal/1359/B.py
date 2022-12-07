from sys import stdin
input = stdin.readline
 
def licz(row, x1, x2):
  row = [-1] + [i for i, e in enumerate(row) if e == "*"] + [len(row)]
  pyk = [x - y - 1 for x, y in zip(row[1:], row[:-1])]
  return sum([(a // 2) * x2 + (a - 2 * (a // 2)) * x1 for a in pyk])
 
q = int(input())
for _ in range(q):
	r,c,x1,x2 = map(int,input().split())
	x2 = min(x2, 2 * x1)
	print(sum([licz(input().strip(), x1, x2) for i in range(r)]))