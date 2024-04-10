n,m,k,t=[int(i) for i in raw_input().split()]

bad = []
for i in range(k):
    bad.append([int(j) for j in raw_input().split()])
def num(x,y):
    cnt=0
    fail = 0
    for i in bad:
        cnt += (i[0] < x or (i[0] == x and i[1] < y))
        if x == i[0] and y == i[1]:
               fail = 1
    if fail:
           return -1
    return m * (x-1) + y - 1 - cnt
for i in range(t):
               x,y = [int(i) for i in raw_input().split()]
               t=num(x,y)
               if t == -1:
                   print "Waste"
                   continue
               t += 2
               if t%3 == 0:
                   print "Kiwis"
               elif t%3 == 1:
                   print "Grapes"
               else:
                   print "Carrots"