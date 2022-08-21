prev = 0
for curr in map(ord, raw_input()):
    diff = prev - curr & 255
    for it in xrange(diff):
        print '..'
        print 'X.'
    print 'X.'
    prev = curr