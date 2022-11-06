n = int(raw_input())
X = 0
for i in xrange(n):
    if raw_input()[1] == '+':
        X += 1
    else:
        X -= 1
print X