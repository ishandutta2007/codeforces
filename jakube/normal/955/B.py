from collections import defaultdict
s = input()
m = defaultdict(int)
for c in s:
    m[c] += 1

cnts = [j for i,j in m.items()]

if len(s) < 4 or len(cnts) > 4 or len(cnts) == 1 or (len(cnts) == 2 and min(cnts) == 1):
    print("No")
else:
    print("Yes")