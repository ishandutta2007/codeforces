raw_input()
print len({x for x in map(int, raw_input().split()) if x != 0})