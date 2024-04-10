x, y = [int(i) for i in raw_input().split()]

i=0
while x*100+y*10 >= 220 and y >= 2:
    if i%2 == 0: #ciel
        if x >= 2:
            x, y = x-2, y-2
        elif x == 1:
            x, y = x-1, y-12
        else:
            y = y-22
    else:
        y = y-2
        if y >= 20:
            y = y-20
        elif y >= 10:
            x, y = x-1, y-10
        else:
            x = x-2
    #print x,y
    i += 1
if i%2:
    print "Ciel"
else:
    print "Hanako"