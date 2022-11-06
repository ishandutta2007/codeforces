n = int(raw_input())
array = [0 for i in xrange(n)]
for i in xrange(n):
    array[i] = raw_input()
for i in array:
    if i[:5] == "miao." and i[-5:] == "lala.":
        print "OMG>.< I don't know!"
    elif i[:5] == "miao.":
        print "Rainbow's"
    elif i[-5:] == "lala.":
        print "Freda's"
    else:
        print "OMG>.< I don't know!"