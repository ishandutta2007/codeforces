n = input()
l = [1, 1]
while l[-1] <= n: l.append(sum(l[-2:]))
print len(l) - 3